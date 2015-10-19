/*
*  For Use in Character and Pawn Classes
*/

// IN HEADER


#define M_ADD_BUTTON(BUTTON) void On##BUTTON##Pressed(); void On##BUTTON##Released();

#define M_ADD_AXIS(AXIS) void Add##AXIS##Input(float speed);

#define M_ADD_BUTTON_TO_PROPERTY(BUTTON,PROPERTY) \
  bool PROPERTY; \
  void On##BUTTON##Pressed(){ PROPERTY = true; }; \
  void On##BUTTON##Released(){ PROPERTY = false; };

#define M_BIND_BUTTON(BUTTON, CONTROLLER)  \
  InputComponent->BindAction(#BUTTON, IE_Pressed, this, &##CONTROLLER##::On##BUTTON##Pressed); \
  InputComponent->BindAction(#BUTTON, IE_Released, this, &##CONTROLLER##::On##BUTTON##Released);

#define M_BIND_AXIS(AXIS,CONTROLLER) \
  InputComponent->BindAxis(#AXIS, this, &##CONTROLLER##::Add##AXIS##Input);
