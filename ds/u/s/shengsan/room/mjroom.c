#include <room.h>
#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
void create()
{
set("short",HIR"["+HIY+"�`�Ю��l�±N�]"+HIR+"]"NOR);
set("long", @LONG
�o�O�@���M�������a�̥𮧪��T�ֳ��ҡA��A�b���A������
���W����ɡA�O�ѤF�𮧬O���F������������A��T���n�ͤ@�P
�ӥ��ӴX��a�A���L�i�O�I�g�b��դ�������ԲӪ��W�h��
�ݬݧG�i��]��������^
LONG
);
set("light",1);
set("no_fight", 1);
set("no_magic", 1);
set("no_spells", 1);
set("exits",([
]));
set("objects",([
__DIR__"mj":1,
]));
set("item_desc",([
"board":"
�@��򥻪��ާ@�G�G  �C�صP������N�X�@�ҡG�@�U�С�1w �C���С�7s
�[�J�P���Gaddin        �}�l�P���Gstart
�N�P�Gmo             ���}�P���Grestart
�ݪ��a1���P�G.1      �ݪ��a2���P�G.2
�ݪ��a3���P�G.3      �ݪ��a4���P�G.4
�ݦۤv���P�G.
��P�Gdump xx        �Y�Geat xx xx        
�I�Gpon              �b�Ggon              
�J�Ghu               ť�Gtin xx           
xx���N�X  �ҡGeat 2w 3w
",
]));
setup();
}
