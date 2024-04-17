export enum Permissions {
    No_PERMISSION = 0,
    READ = 1 << 0,
    WRITE = 1 << 1,
    DELETE = 1 << 2,
    CREATE_USER = 1 << 3,
    DELETE_USER = 1 << 4,
}
