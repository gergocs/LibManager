import {Routes} from '@angular/router';
import {LoginComponent} from "./components/login/login.component";
import {RegisterComponent} from "./components/register/register.component";
import {AuthGuardService} from "./services/auth-guard.service";
import {HomeComponent} from "./components/home/home.component";
import {ModifyPermissionComponent} from "./components/modify-permission/modify-permission.component";

export const routes: Routes = [
    {path: '', pathMatch: 'full', component: HomeComponent},
    {path: 'login', component: LoginComponent},
    {path: 'register', component: RegisterComponent, canActivate: [AuthGuardService]},
    {path: 'updateUser', component: ModifyPermissionComponent, canActivate: [AuthGuardService]},
    {path: '**', redirectTo: '', pathMatch: 'full'},
];
