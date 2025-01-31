import { InnerStuffComponent } from './../inner-stuff/inner-stuff.component';
import { CommonModule } from '@angular/common';
import { Component, Input } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { RouterModule } from '@angular/router';

@Component({
  selector: 'app-error',
  standalone: true,
  imports: [CommonModule, FormsModule, InnerStuffComponent, RouterModule],
  templateUrl: './error.component.html',
  styleUrls: ['./error.component.css']
})
export class errorComponent {
  message: string = 'Letter already guessed';
  @Input() test!: string;
}
