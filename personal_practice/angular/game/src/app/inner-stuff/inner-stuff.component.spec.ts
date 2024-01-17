import { ComponentFixture, TestBed } from '@angular/core/testing';

import { InnerStuffComponent } from './inner-stuff.component';

describe('InnerStuffComponent', () => {
  let component: InnerStuffComponent;
  let fixture: ComponentFixture<InnerStuffComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [InnerStuffComponent]
    })
    .compileComponents();
    
    fixture = TestBed.createComponent(InnerStuffComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
