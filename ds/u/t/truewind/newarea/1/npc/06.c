inherit NPC;
void create()
{
  set_name("���", ({ "Xiao-er","Xiao","er","xiao" }) );
  set("gender", "�k��" );
  set("long",@LONG
���O�^�ު��n�n�f�A�K���Ӫ��ͤk�A�̾ժ����Ʊ��O�ܰs�A�t�~��
�j�o�@�ަn���C�o��ۤ@ŧ�S�ӲH��I�ߡA¸����ȡA���H�H���۫�
�۬K���Ӫ��ȤH�C
LONG
);      
  set("age",20);
  set("level",14);
  set("race","human");
  setup();
  carry_object(__DIR__"armor/06")->wear();
}