inherit MOBROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
 �A�{�b�Ө�@�B���L�ߪ��a��, �@�}�}��������
 �Ө�, ��W���@�諸�ͥ��b���T�T���s��, �n���w��A
 �Ө�o��, �������F��M�_����}, �Ať�줣���B���H
 ����n���C
 
LONG
 );
 
 set("exits",(["north":__DIR__"en5",
               "east":__DIR__"en4",
               "southwest":__DIR__"en2",
     ]));
 
        set("outdoors","land");
        set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
                    __DIR__"npc/chan",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
}

