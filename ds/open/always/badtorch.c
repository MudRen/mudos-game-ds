// An example book
inherit ITEM;
void create()
{
set_name("�N��������",({"torch","badtorch"}));
set_weight(100);
set("value",0);
set("unit","��");
set("long","�@��N��������C\n");
setup();
}

int do_use(object me,string arg)
{
      tell_object(me,"�o�Ӥ���w�g�N���F!\n");	
      return 1;
}
