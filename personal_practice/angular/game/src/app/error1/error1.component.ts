import { InnerStuffComponent } from '../inner-stuff/inner-stuff.component';
import { CommonModule } from '@angular/common';
import { Component, Input } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { RouterModule } from '@angular/router';

@Component({
  selector: 'app-error1',
  standalone: true,
  imports: [CommonModule, FormsModule, InnerStuffComponent, RouterModule],
  templateUrl: './error1.component.html',
  styleUrls: ['./error1.component.css']
})
export class error1Component {
  message: string = 'Guess must be a letter';
  @Input() test!: string;
}
