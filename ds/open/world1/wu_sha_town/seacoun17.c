#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�·t���ܮw");
set("long",@LONG
�A�@��i�o��, �ߨ�Q���󪺯��Ǩ��~�F�@��, �~���~�o�{
�o�̭�ӴN�O���p�ӥ�����a��! �̦M�I���a�詹���N�O�̦w��
���a��, �ַ|�Q�쨫�p�Ӫ��`���N�b���F�q�O? �ӥB�o�̩|�O�u
�a, �ܤ֦��H�|��, �A�ݨ줤�����@�ӤH���b�s��, �ݨӫK�O�Y
�Y�a...?
LONG
    );
 set("exits",(["east":__DIR__"seacoun16",
]));
 set("objects", ([__DIR__"../npc/jacklin" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
}             