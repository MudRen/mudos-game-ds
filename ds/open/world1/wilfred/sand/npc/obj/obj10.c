inherit ITEM;
void create()
{
  set_name("��÷",({"rope"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�»s����÷�A�Q�����@�ΡC");
    set("value",100);
  }
  setup();
}