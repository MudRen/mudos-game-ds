// �]�w�̦h��� 8 �i�P
inherit ITEM;

void create()
{
  set_name("�P��", ({ "card box","box" }) );
  set("long","�ΨӸ� Magic Card ���P���A�q�`���ɩιC���ɤ~�|�Ψ�C\n");
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("volume",6);
    set("value",100);
  }
  setup();
  set_max_capacity(8);
  set_max_encumbrance(12);
}
