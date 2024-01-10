import { GetInput } from './getInput';
import { Component, Input } from '@angular/core';
import { CommonModule } from '@angular/common';
import { RouterOutlet } from '@angular/router';
import { GameComponent } from './game/game.component';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-root',
  standalone: true,
  /*template: `
    <main>
      <header class="brand-name">
      <img class="brand-logo" src="/personal_practice/angular/project/src/favicon.ico" alt="logo"
  aria-hidden="true">
      </header>
      <section class="content">
        <app-game></app-game>
      </section>
    </main>
`*/
  imports: [CommonModule, RouterOutlet, GameComponent, FormsModule],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'Game';

  @Input() user!: Input;
  getInput: GetInput = {character: `${this.user}`};
  print()
  {
    alert(`input: ${this.getInput.character}`);
  }
}


