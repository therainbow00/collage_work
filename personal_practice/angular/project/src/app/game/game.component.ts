import { Component, PipeTransform } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import { Transform } from 'stream';

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
   usersWord: string[] = [];
   word: string[] = [ 'aardvark', 'Bear', 'cat', 'Dog', 'elephant', 'Fox', 'giraffe', 'Hippo', 'iguana', 'Jaguar', 'kangaroo', 'Lion', 'monkey', 'Narwhal', 'ostrich', 'Penguin', 'quail', 'Rabbit', 'shark', 'Tiger', 'unicorn', 'Vulture', 'whale', 'Xerus', 'yak', 'Zebra', 'ant', 'Bat', 'cow', 'Deer', 'eagle', 'Frog', 'goat', 'Hamster', 'impala', 'Jellyfish', 'koala', 'Lemur', 'mole', 'Numbat', 'otter', 'Parrot', 'quokka', 'Raccoon', 'sloth', 'Turtle', 'uakari', 'Viper', 'walrus', 'Xiphias', 'yabby', 'Zorilla', 'anaconda', 'Beaver', 'camel', 'Duck', 'emu', 'Flamingo', 'gorilla', 'Hedgehog', 'inchworm', 'Jackal', 'kiwi', 'Llama', 'mouse', 'Nutria', 'owl', 'Peacock', 'quetzal', 'Rhino', 'skunk', 'Turkey', 'urchin', 'Vole', 'wombat', 'Xantus', 'yakut', 'Zebra shark' ];

   number: number = Math.floor(Math.random() * (100 - 1 + 1) + 1);
   randomWord: string = this.word[this.number];

   Transfrom(value: string): string
   {
      let characters = value.split('');

      for (let i = characters.length - 1; i > 0; i--)
      {
        let j = Math.floor(Math.random() * (i + 1));
        [characters[i], characters[j]] = [characters[j], characters[i]];
      }
      return characters.join('');
   }
   characters: string = this.Transfrom(this.randomWord);

   Display(): void
   {
      if (this.User.trim() != '')
      {
         this.usersWord.push(this.User);
         this.User = '';
      }
   }
}
