import { CommonModule } from '@angular/common';
import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { errorComponent } from '../error/error.component';
import { error1Component } from '../error1/error1.component';

@Component({
    selector: 'app-inner-stuff',
    standalone: true,
    templateUrl: './inner-stuff.component.html',
    styleUrls: ['./inner-stuff.component.css'],
    imports: [CommonModule, FormsModule, errorComponent, error1Component]
})
export class InnerStuffComponent {
  User: string = '';
  usersWord: string[] = [];
  word: string[] = ['aardvark', 'Bear', 'cat', 'Dog', 'elephant', 'Fox', 'giraffe', 'Hippo', 'iguana', 'Jaguar', 'kangaroo', 'Lion', 'monkey', 'Narwhal', 'ostrich', 'Penguin', 'quail', 'Rabbit', 'shark', 'Tiger', 'unicorn', 'Vulture', 'whale', 'Xerus', 'yak', 'Zebra', 'ant', 'Bat', 'cow', 'Deer', 'eagle', 'Frog', 'goat', 'Hamster', 'impala', 'Jellyfish', 'koala', 'Lemur', 'mole', 'Numbat', 'otter', 'Parrot', 'quokka', 'Raccoon', 'sloth', 'Turtle', 'uakari', 'Viper', 'walrus', 'Xiphias', 'yabby', 'Zorilla', 'anaconda', 'Beaver', 'camel', 'Duck', 'emu', 'Flamingo', 'gorilla', 'Hedgehog', 'inchworm', 'Jackal', 'kiwi', 'Llama', 'mouse', 'Nutria', 'owl', 'Peacock', 'quetzal', 'Rhino', 'skunk', 'Turkey', 'urchin', 'Vole', 'wombat', 'Xantus', 'yakut', 'Zebra shark'];

  number: number = Math.floor(Math.random() * (100 - 1 + 1) + 1);
  randomWord: string = this.word[this.number];

  Convert(): string
  {
    let characters = this.randomWord.split('');

    for (let i = characters.length - 1; i > 0; i--)
    {
      let j = Math.floor(Math.random() * (i + 1));
      [characters[i], characters[j]] = [characters[j], characters[i]];
    }
    return characters.join('');
  }
  scrambledWord: string = this.Convert();
  scrambledCharacters: string[] = this.scrambledWord.split('');
  correct: number = 0;
  count: number = 0;

  roundCount: number = 0;
  CheckCharacter(letter: string): void
  {
    let found = false;
    for (let i = 0; i < this.scrambledCharacters.length; i++)
    {
      if (letter == this.scrambledCharacters[i]) this.correct++;
      else found = true;
    }

    if (found) this.usersWord.push(this.User);
  }

  AlreadyGuessed(letter: string): void {for (let i = 0; i < this.usersWord.length; i++) if (letter == this.usersWord[i]) window.location.href = '/error';}

  BackgroundColorGradient(): string
  {
    if (0 < this.roundCount && this.roundCount < 33) return `linear-gradient(to right, red, red ${this.roundCount}% , white ${this.roundCount}%,  white)`;
    else if (33 < this.roundCount && this.roundCount < 66) return `linear-gradient(to right, yellow, yellow ${this.roundCount}% , white ${this.roundCount}%,  white)`;
    else return `linear-gradient(to right, green, green ${this.roundCount}% , white ${this.roundCount}%,  white)`;
  }

  Display(): void
  {
    if (this.User === 'quit') window.location.href = '/route';
    else
    {
      if (this.User.length > 1) window.location.href = '/error2';
      else
      {
        if (isNaN(Number(this.User)))
        {
          let letter = this.User[0].trim();
          this.AlreadyGuessed(letter);
          this.CheckCharacter(letter);
          this.roundCount = Math.round((this.correct / this.randomWord.length) * 100);
          this.count++;
          this.User = '';
        }
        else window.location.href = '/error1';
      }
    }
  }
}
