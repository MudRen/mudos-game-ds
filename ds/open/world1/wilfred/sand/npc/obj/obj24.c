inherit ITEM;
void create()
{
  set_name("����",({"paper"}));
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else set("value",1000);
  setup();
}