import {Injectable} from '@angular/core';
import {Router} from "@angular/router";
import {HttpClient, HttpHeaders} from "@angular/common/http";
import {User} from "../models/user";
import {UserLogin} from "../models/user-login";
import {StorageService} from "./storage.service";
import {Permissions} from "../models/permissions";

@Injectable({
    providedIn: 'root'
})
export class AuthService {

    private host: string = "http://localhost:8080";

    user: User | undefined;

    constructor(protected router: Router, protected http: HttpClient, protected storage: StorageService) {
        this.user = this.storage.getUserInfo();
    }

    private createHeader(): HttpHeaders {
        return new HttpHeaders({
            'Content-Type': 'application/json',
            'token': this.user?.token || ""
        });
    }

    isAuthenticated(): boolean {
        return this.user !== undefined;
    }

    hasPermission(permission: Permissions): boolean {
        if (this.isAuthenticated()) {
            // @ts-ignore
            return (this.user.permissions & permission) != 0;
        }

        return false;
    }

    login(data: UserLogin) {
        if (this.user == undefined && (data.username === "" || data.password === "")) {
            //TODO show error message
            return;
        }

        this.http.post(this.host + "/getUser", JSON.stringify(data), {
            headers: this.createHeader()
        }).subscribe((res: any) => {
            this.user = res;
            this.router.navigate(['/']);
            this.storage.set("user", JSON.stringify(this.user));
        });
    }

    checkLoggedIn() {
        if (this.user == undefined) {
            this.router.navigate(['/login']);
        }

        this.http.post(this.host + "/getUser", "", {
            headers: this.createHeader()
        }).subscribe({
            next: (res: any) => {
                this.user = res;
                this.storage.set("user", JSON.stringify(this.user));
            },
            error: (error) => {
                this.router.navigate(['/login']);
                this.storage.remove("user")
            }
        });
    }

    logout() {
        this.user = undefined;
        this.router.navigate(['/login']);
    }

    getUsers() {
        return this.http.get(this.host + "/getUsers", {
            headers: this.createHeader()
        });
    }

    getUserPermissions(username: string) {
        return this.http.get(this.host + "/getUserPermission/" + username, {
            headers: this.createHeader()
        });
    }

    updateUserPermissions(username: string, permissions: number) {
        this.http.post(this.host + "/updateUserPermission", JSON.stringify({
            username: username,
            permission: permissions
        }), {
            headers: this.createHeader()
        }).subscribe((res: any) => {
            console.log(res);
        });
    }
}
