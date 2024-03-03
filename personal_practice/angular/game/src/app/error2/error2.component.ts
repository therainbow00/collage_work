import { InnerStuffComponent } from '../inner-stuff/inner-stuff.component';
import { CommonModule } from '@angular/common';
import { Component, Input } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { RouterModule } from '@angular/router';

@Component({
  selector: 'app-error2',
  standalone: true,
  imports: [CommonModule, FormsModule, InnerStuffComponent, RouterModule],
  templateUrl: './error2.component.html',
  styleUrls: ['./error2.component.css']
})
export class error2Component {
  message: string = 'Guess only one character';
  @Input() test!: string;
}
