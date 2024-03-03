import { CommonModule } from '@angular/common';
import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { RouterModule } from '@angular/router';

@Component({
  selector: 'app-route',
  standalone: true,
  imports: [CommonModule, FormsModule, RouterModule],
  templateUrl: './route.component.html',
  styleUrls: ['./route.component.css']
})
export class routeComponent {
  message: string = 'route';
}
