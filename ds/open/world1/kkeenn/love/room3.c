inherit BANK;
void create()
{
        set("short", "����������");
        set("long", @LONG
�A�Ө�@�������~���Фl���Y�A�a���\�������M���Ǫ�����ۡA�i
���o�a���D�H�O�h�򪺲ӤߡA�i���A�o�̪F�ݦ�ݡA�N�u���k�ʡA���G��
�ӫ������u���k�ʦӤw�a�C
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"room2",  
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/dwller" : 3,
__DIR__"npc/bankman" : 1,
]));
        set("light",1);
        setup();
}

