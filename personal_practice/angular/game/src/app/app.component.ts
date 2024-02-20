import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { RouterModule, RouterOutlet} from '@angular/router';
import { InnerStuffComponent } from "./inner-stuff/inner-stuff.component";

@Component({
    selector: 'app-root',
    standalone: true,
    templateUrl: './app.component.html',
    styleUrl: './app.component.css',
    imports: [CommonModule, RouterModule, InnerStuffComponent, RouterOutlet]
})

export class AppComponent {
  title = 'game';
}
