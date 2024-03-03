import { ComponentFixture, TestBed } from '@angular/core/testing';

import { error2Component } from './error2.component';

describe('error2Component', () => {
  let component: error2Component;
  let fixture: ComponentFixture<error2Component>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [error2Component]
    })
    .compileComponents();

    fixture = TestBed.createComponent(error2Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
