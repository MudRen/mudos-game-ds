inherit NPC;
void create()
{
  set_name("�`��", ({ "Wan-er","Wan","wan","er" }) );
  set("gender", "�k��" );
  set("long",@LONG
�`��O�K���Ӫ��ͤk�A���Ӥ~�i�ӡC�`��S����௷���h���A���L
�g���@���n���A�S��q�ۡA��ۤ@ŧ�Z�����S�a�H����ȡA�O���@�f
�����C
LONG
);      
  set("age",20);
  set("level",12);
  set("race","human");
  setup();
  carry_object(__DIR__"armor/03")->wear();
}