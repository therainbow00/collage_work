import { Component, Input } from '@angular/core';
import { CommonModule } from '@angular/common';
import { GetInput } from '../getInput';
import { FormControl, FormsModule } from '@angular/forms';

@Component({
   selector: 'app-game',
   standalone: true,
   imports: [CommonModule, FormsModule],
   templateUrl: './game.component.html',
   styleUrls: ['./game.component.css']
})
export class GameComponent
{
   user = new FormControl();
   User: string = '';
   @Input() userInput: GetInput | undefined;
   //getInput: GetInput = {character: this.User};

   list: string[] = [];

   Display(): void
   {
      alert(`input - ${this.User}`);
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
