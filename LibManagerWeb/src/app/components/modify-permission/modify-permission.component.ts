import {Component} from '@angular/core';
import {AuthService} from "../../services/auth.service";
import {Router} from "@angular/router";
import {Permissions} from "../../models/permissions";
import {MatFormField, MatFormFieldModule, MatLabel} from "@angular/material/form-field";
import {MatOption, MatSelect} from "@angular/material/select";
import {FormsModule} from "@angular/forms";
import {NgIf} from "@angular/common";
import {MatCheckbox} from "@angular/material/checkbox";
import {MatInputModule} from "@angular/material/input";
import {MatButton} from "@angular/material/button";
import {StorageService} from "../../services/storage.service";

@Component({
    selector: 'app-modify-permission',
    standalone: true,
    imports: [
        MatFormField,
        MatFormFieldModule,
        MatSelect,
        MatLabel,
        MatCheckbox,
        MatInputModule,
        FormsModule,
        MatOption,
        NgIf,
        MatCheckbox,
        MatButton
    ],
    templateUrl: './modify-permission.component.html',
    styleUrl: './modify-permission.component.css'
})
export class ModifyPermissionComponent {

    users: string[] = [];
    selectedUser: string = "";
    permissions: Permissions[] = [];
    isPermissionEnabled: boolean = false;
    protected readonly Permissions = Permissions;

    constructor(protected authService: AuthService, protected router: Router, protected storage: StorageService) {
        if (!this.authService.hasPermission(Permissions.CREATE_USER)) {
            router.navigate(['/']);
        }

        this.authService.checkLoggedIn();

        this.authService.getUsers().subscribe({
        next :(res: any) =>
        {
            this.users = (res["username"] as string[]).filter((value) => value !== this.authService.user?.username);
        },
        error: (err: any) => {
            console.log(err)
            this.router.navigate(['/login'])
            this.storage.remove("user")
        }});
    }

    getUserPermissions() {
        this.authService.getUserPermissions(this.selectedUser).subscribe((res: any) => {
            let permission: number = res["permissions"];
            let enumIterator: keyof typeof Permissions;

            for (enumIterator in Permissions) {
                // @ts-ignore
                if (permission & Permissions[enumIterator]) {
                    // @ts-ignore
                    this.permissions.push(Permissions[enumIterator]);
                }
            }

            this.isPermissionEnabled = true;
        });
    }

    validatePermission(permission: Permissions) {
        return this.permissions.includes(permission);
    }

    updatePermissionList(permission: Permissions) {
        if (this.permissions.includes(permission)) {
            this.permissions = this.permissions.filter((value) => value !== permission);
        } else {
            this.permissions.push(permission);
        }
    }

    onUpdateClicked() {
        let permission: number = 0;

        for (let it of this.permissions) {
            permission |= it;
        }

        this.authService.updateUserPermissions(this.selectedUser, permission);
    }
}
