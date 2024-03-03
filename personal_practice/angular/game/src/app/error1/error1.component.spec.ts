import { ComponentFixture, TestBed } from '@angular/core/testing';

import { error1Component } from './error1.component';

describe('error1Component', () => {
  let component: error1Component;
  let fixture: ComponentFixture<error1Component>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [error1Component]
    })
    .compileComponents();

    fixture = TestBed.createComponent(error1Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
