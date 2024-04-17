import {Injectable} from '@angular/core';
import {ActivatedRouteSnapshot, Router, RouterStateSnapshot} from "@angular/router";
import {AuthService} from "./auth.service";
import {Permissions} from "../models/permissions";

@Injectable({
    providedIn: 'root'
})
export class AuthGuardService {

    constructor(public auth: AuthService, public router: Router) {
    }

    canActivate(route: ActivatedRouteSnapshot,
                state: RouterStateSnapshot): boolean {
        if (!this.auth.isAuthenticated()) {
            this.router.navigate(['login']);
            return false;
        }

        if (route.url.length == 0) {
            return false;
        }

        return (route.url[0].path === "register" && this.auth.hasPermission(Permissions.CREATE_USER)
            || route.url[0].path === "updateUser" && this.auth.hasPermission(Permissions.CREATE_USER | Permissions.DELETE_USER));
    }
}
