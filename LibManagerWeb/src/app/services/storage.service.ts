import { Injectable } from '@angular/core';
import {User} from "../models/user";

@Injectable({
  providedIn: 'root'
})
export class StorageService {

  constructor() { }

  get(key: string): string | null {
    return localStorage.getItem(key);
  }

  getUserInfo(): User | undefined {
    if (this.isKeyExist('user')) {
      return JSON.parse(<string>this.get('user')) as User;
    }

    return undefined;
  }

  set(key: string, value: string): void {
    localStorage.setItem(key, value);
  }

  remove(key: string): void {
    localStorage.removeItem(key);
  }

  clear(): void {
    localStorage.clear();
  }

  isKeyExist(key: string): boolean {
    return localStorage.getItem(key) !== null;
  }
}
