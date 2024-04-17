import {Permissions} from "./permissions";

export interface User {
    username: string;
    token: string;
    permissions: Permissions;
}
