import { Routes, RouterModule } from '@angular/router';
import { InnerStuffComponent } from './inner-stuff/inner-stuff.component';
import { AppComponent } from './app.component';
import { NgModule } from '@angular/core';
import { errorComponent } from './error/error.component';

export const routes: Routes = [
  {path: 'game', component: InnerStuffComponent},
  {path: 'home', component: AppComponent},
  {path: 'error', component: errorComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})

export class AppRoutingModule {}
