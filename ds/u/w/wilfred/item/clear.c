inherit ITEM;
void create()
{ set_name("全清",({"clear"}));
  set("long","有時身上會弄了一些東西無法 dest 時, 用這個\n");
  set("unit","個");
  setup(); }
void init()
{ add_action("do_clear","clear"); }
int do_clear()
{
  int i;
  object *inv,me=this_player();
  inv = all_inventory(me);
  for(i=1; i<sizeof(inv); i++)
  {
    if( stringp(inv[i]->query("equipped")) ) inv[i]->unequip();
    destruct(inv[i]);
  }
  write("ok\n");
  return 1;
}
