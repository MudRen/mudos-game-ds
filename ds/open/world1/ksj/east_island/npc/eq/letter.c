#include <path.h>
inherit ITEM;

void create()
{
  set_name("�H", ({"hoshiakari's letter","letter"}) );
  set("long",@long
�@�ʬh�͡D�P���g����V�D�������H�C

    �����A�����e�ڲv��̤l�Χ����i�h�e�����L���Q��Ѫ��A�o
    �N�~�o�{�h�~�e�Q�Ѫ��ۨ�����V�D���l�A��ɥѩ�s���E���A
    �ɭP�~�|�ӻP�A�����ˬ�t�D���o�ͽĬ�A�Ӧ��ɤѪ��S�v����
    ŧ�A�V�ä��ɭP�p���������l�������`�A�ӧڭ̤@��H�h�a�۩p
    �Ѱk�^�����A�N�R�U�ӫ�ڤ~�o�{�䤤���~�|�A�ӧڤ]�`�P�\��
    �A�p���p�w���j�F�A�]���N�Ʊ����]�G�i�D�p�A�p�����˴N��b
    ���L�~���p�˪L���A���H���p���L�ȪZ�����j�A�p�i�P���P��
    �e���C                                        �h�͡D�P��

long);
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("volume",1);
    set("no_sell",1);
  }
  setup(); 
}
