inherit ITEM;
void create()
{ set_name("���M",({"clear"}));
  set("long","���ɨ��W�|�ˤF�@�ǪF��L�k dest ��, �γo��\n");
  set("unit","��");
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
