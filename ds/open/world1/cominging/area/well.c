#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", YEL"�j��"NOR);
        set("long",@LONG
�o�̬O�B�F�������s�����ߥj�����A�o�����M�s�j���A���o�٦��@
�Ǥ��q�o�̸g�L�A�O�A���}�����@�I���㪺�A�o�̨õL����O���A�u�a
�W��Ӫ��O����ģ�U�ӡA�Ӧb�A�}�U�����y���G�g���@�ǨǪ����⪫��
�A�n���i�H���_�Ӫ��ˤl�C
LONG
        );
        set("exits", ([
  "east" : __DIR__"well4.c", 
"west" : __DIR__"well2.c",
"south" : __DIR__"well3.c",
"north" : __DIR__"well1.c",
"up" : __DIR__"boo-lin.c",])); 
        set("item_desc",([
"���⪫��":"�G�������F��A�ݰ_�Ӧn���F�l[sand]�����C\n",
        ]));
        set("no_clean_up", 0);
        setup();
} 
void init()
{
    add_action("do_scrape","scrape");
}
int do_scrape(string arg)
{ 
    object x,me=this_player(); 
    if(this_object()->query_temp("do_scraped")==1) return notify_fail("���w�g���H���L���ˤl�A�{�b�b�I���ѡA�u�n�A�����׶��F..\n");
    if(!me) return 0;
    if(arg != "sand") return notify_fail("�A�n������??\n");
    message_vision("\n"+me->name()+"���F�@�I���F�_�ӡC\n",me);
    x=new("/open/world1/cominging/area/npc/obj/metallizer")->move(environment(me));
    set_temp("do_scraped",1); 
    call_out("do_scrapedd",1800,this_object());
    return 1;
}
void do_scrapedd()
{ 
    delete_temp("do_scraped"); 
    return;
}

