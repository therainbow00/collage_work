import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { RouterModule, RouterOutlet} from '@angular/router';
import { InnerStuffComponent } from "./inner-stuff/inner-stuff.component";
import { routeComponent } from './route/route.component';
import { errorComponent } from './error/error.component';
import { rulesComponent } from './rules/rules.component';

@Component({
    selector: 'app-root',
    standalone: true,
    templateUrl: './app.component.html',
    styleUrls: ['./app.component.css'],
    imports: [CommonModule, RouterModule, InnerStuffComponent, RouterOutlet, routeComponent, errorComponent, rulesComponent],
})

export class AppComponent {}
