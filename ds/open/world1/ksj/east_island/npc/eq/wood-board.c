inherit ITEM;

void create()
{
  set_name("�i�ܵP", ({"wood board","board"}) );
  set("long",@LONG
�@�Ӥ�s���i�ܵP�A�W����ۡG

    �Ѫ�  ����  �H�����ɡA�����I�ǡI

                              ��t

LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("no_sac",1);
    set("unit", "��");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
