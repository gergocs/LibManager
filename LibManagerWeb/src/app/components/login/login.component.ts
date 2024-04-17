import {Component} from '@angular/core';
import {MatFormField, MatLabel} from "@angular/material/form-field";
import {MatInput} from "@angular/material/input";
import {MatIconButton} from "@angular/material/button";
import {MatIcon} from "@angular/material/icon";
import {FormsModule} from "@angular/forms";
import {UserLogin} from "../../models/user-login";
import {AuthService} from "../../services/auth.service";
import {Router} from "@angular/router";

@Component({
    selector: 'app-login',
    standalone: true,
    imports: [
        MatFormField,
        MatInput,
        MatIconButton,
        MatIcon,
        MatLabel,
        FormsModule
    ],
    templateUrl: './login.component.html',
    styleUrl: './login.component.css'
})
export class LoginComponent {
    hide = true;
    userLogin: UserLogin = {
        username: "",
        password: ""
    };

    constructor(protected authService: AuthService, protected router: Router) {
        if(this.authService.isAuthenticated()) {
            router.navigate(['/']);
        }
    }

    login() {
        this.authService.login(this.userLogin);
    }
}
