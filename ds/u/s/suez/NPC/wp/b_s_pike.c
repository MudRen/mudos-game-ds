#include <weapon.h>
#include <ansi.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
set_name("�Q�D�j",({"blake snake pike","pike"}));

set_weight(7000);
          if( clonep() )
                      set_default_object(__FILE__);
          else {
set("long",@LONG
    �@���q��Q�¡A�s�y�b���x�۶¦���A���K�j�A�j��W��
���K�K�³ª��貪�A�o�O�K�������Ѥ�e���L���o�N�̤l��l
�ª��L���C�ѩ��l�¨����z�A���׬O�j�j�Z�άO�K������
�S��k�i�{�������¤O�A�ҥH���Ѥ�Ѥj�j�Z���ܤƥX�@�M��
���F�ʤS�¤O�Q�����j�k�A�j�쪺�貪�ڻ��N�O�H�j�k��X��
�A�Ӯ�l�´N�ѳo�Ǩ貪���⮩�X�j�k�����N�C���Oť���o��
�j�٦��t�@�ӪZ�L�������A���N���o�Ӫ��F�C
LONG);
set("unit", "��");
set("value", 17000);
set("material","iron");
}
set("limit_int",90);
set("limit_dex",70);

set("weapon_prop/dex",7);
set("weapon_prop/hit",5);
set("weapon_prop/armor", 27);
/*
set("combat_msg", ({
     HIC"$N���O�@�R�A$w�W���H��p������N$n�ιγ��I"NOR,
     HIY"$w�b$N��W���p�����@��A�H���p���α��ժ��t�ק�V$n��$l"NOR,
    HIG"$N�⤤��$w��M�����I�H��$N���ʧ@�X�{�b$n��$l����A���۴N�O�����@��I"NOR,
     }) );
*/
   init_fork(70);


setup();
}     
