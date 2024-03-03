import { ComponentFixture, TestBed } from '@angular/core/testing';

import { routeComponent } from './route.component';

describe('routeComponent', () => {
  let component: routeComponent;
  let fixture: ComponentFixture<routeComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [routeComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(routeComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
