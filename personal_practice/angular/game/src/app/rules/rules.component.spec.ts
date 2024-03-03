import { ComponentFixture, TestBed } from '@angular/core/testing';

import { rulesComponent } from './rules.component';

describe('rulesComponent', () => {
  let component: rulesComponent;
  let fixture: ComponentFixture<rulesComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [rulesComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(rulesComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
