// ���� mob �����, �H�K���a�ί��O�Ũ� hest ���n�� mob (�Ҧp�������C�����s or �u�������s)
// wilfred@DS
// note by alick,hest��checking���ө�^����O��~!
// �i�H�g�Ӥ���Hest���M��b��item��

inherit ITEM;
void create()
{
  set_name("������",({"notgo"}));
  set_weight(10);
set("no_sac", 1);
set("no_get", 1);
set("no_drop", 1);
set("no_give", 1);
// add no sac,drop,get by alick, invis�F��item�@�˯�Drop,get! by alick
  setup();
  set_temp("invis",1);
}

void init()
{
if( environment(this_object())->is_room()  ) 
{
	destruct(this_object());
	return;
}
// add by alick for fix bug
    /* bug , �J�÷d... fixed by -Acme- */
    if( !userp(this_player()) ) add_action("action","",1);
}

int action()
{
if( !userp(this_player()) ) 
{
// add by -alick for fix bug
  message_vision("\n$N�n�������Ұ� ....... \n\n",this_player());
  return 1;
}
}
