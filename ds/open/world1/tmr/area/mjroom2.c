#include <room.h>
#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
void create()
{
set("short",HIR"[�±N��]"NOR);
set("long", @LONG
�o�O��{�̪��@���K�ǡA�Ǥ��\�]�F�X�i�±N��C�o�̪����u��
���t�A�¦����O�w�A�t�t�����O���A�٦��@�ѿ@�@���Ϩ��A�O�H��
�Q���Z�����Pı�C������W���p�ժO�]��������^�W�Y�g�ۤ@�ǭ�
�ê��p�r�C
LONG
);
set("light",1);
set("no_fight", 1);
set("no_cast", 1);
set("no_exert", 1);
set("no_magic", 1);
set("no_steal", 1);
	set("no_whisper", 1);
set("exits",([
"west": __DIR__"mjroom",
]));
set("objects",([
"/obj/mjlady2":1,
]));
set("item_desc",([
"board":@BOARD

�@��򥻪��ާ@�G �C�صP������N�X�@�ҡG�@�U�С�1w �C���С�7s

�[�J�P���Gaddin		�N�P�Gmo �άO 0
�]�w��`: bet <�ƶq>	��P�Gdump xx �άO dd xx
�}�l�P���Gstart		�Y�Geat xx xx
���}�P���Grestart	�I�Gpon
�ݪ��a1���P�G.1		�b�Ggon (�t�b�� gon xx)
�ݪ��a2���P�G.2		�J�Ghu
�ݪ��a3���P�G.3		�۰ʳ]�w: setmj (�Բӫ��O�Х� help setmj)
�ݪ��a4���P�G.4	
�ݦۤv���P�G.		(xx���N�X  �ҡGeat 2w 3w)

BOARD,
]));
setup();
}
