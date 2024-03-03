import { InnerStuffComponent } from '../inner-stuff/inner-stuff.component';
import { CommonModule } from '@angular/common';
import { Component, Input } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { RouterModule } from '@angular/router';

@Component({
  selector: 'app-rules',
  standalone: true,
  imports: [CommonModule, FormsModule, InnerStuffComponent, RouterModule],
  templateUrl: './rules.component.html',
  styleUrls: ['./rules.component.css']
})
export class rulesComponent {}
