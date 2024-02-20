import { ComponentFixture, TestBed } from '@angular/core/testing';

import { errorComponent } from './error.component';

describe('errorComponent', () => {
  let component: errorComponent;
  let fixture: ComponentFixture<errorComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [errorComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(errorComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
