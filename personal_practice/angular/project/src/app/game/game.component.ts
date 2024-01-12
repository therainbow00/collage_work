import { GetInput } from './../getInput';
import { Component, Input } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

@Component({
   selector: 'app-game',
   standalone: true,
   imports: [CommonModule, FormsModule],
   templateUrl: './game.component.html',
   styleUrls: ['./game.component.css']
})
export class GameComponent
{
   User: string = '';
   list: string[] = [];

   Display(): void
   {
      if (this.User.trim() != '')
      {
         this.list.push(this.User);
         this.User = '';
      }
   }
   /*Display2(): void
   {
      alert(`input - ${this.getInput.character}`);
   }*/
}
