inherit MOBROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
 �A�Ө�F�F�_�A�L������, �o�̦��\�h������, ��
 �b�V�O�������, �L�̪����@�w�@�w���y�U, �A���_��
 �N�O�L�H���˪L�`�B�F�C 
 
LONG
    );
 
 set("exits",(["north":__DIR__"en6",
               "west":__DIR__"en3",
             ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",40);
        set("mob_amount",3);    
        set("mob_object",({     
            __DIR__"npc/cutter",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
}

