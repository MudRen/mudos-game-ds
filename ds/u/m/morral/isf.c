inherit ITEM;

void create()
{
  set_name("I'S �̲ץ�(eeman �M��)", ({ "IS COMIC" }));
  set_weight(100);
  if( clonep() )
  set_default_object(__FILE__);
  else {
        set("unit","��");
        set("long",
                 "�o�O�ۥ��M�e��I'S,�]���OEEMAN �M�Υ�,"
                 "�ҥH�U�����Ӳq�o��̭��Oԣ(18�T)\n");
        set("value",10000);
}
}
