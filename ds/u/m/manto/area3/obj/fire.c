inherit ITEM;
void create()
{
set_name("�j�j�i�H�ϥΪ�����",({"fire"}));
set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                 set("unit", "��");
  set("no_auc", 1);
  set("no_sac", 1);
  set("no_sell", 1);
  set("no_drop", 1);
  set("no_put", 1);
        }
  setup();
}
