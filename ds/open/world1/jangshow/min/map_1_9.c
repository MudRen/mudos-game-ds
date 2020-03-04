#include <ansi.h>
inherit ROOM;
//²��覡���^�O room,�i�ɥR
void create()
{
        set("short", "�۪O��");
        set("long", @LONG

LONG
);
        set("exits",([
        "south" : __DIR__"map_2_9",
        "east" : __DIR__"map_1_10",
        "west" : __DIR__"map_1_8",
        ]));
        set("item_desc",([
        "����":"�@������A�W���g�ۡy��Ū(account)�z�A�����Dĭ�t�ۤ���N��H\n", 
        "����":"�@������A�W����� [godcome + xxx] ���G��A�����D�O�@����Ϊ��H\n",
        ]));
        setup();
        set("map_long",1);     //show map as long
}
void init()
{
add_action("do_account","account");
add_action("do_godcome","godcome");
}


/***********************�H�U���i�ɥR��************************/   
int do_account(string arg)
{ 
    object me=this_player(),obj; 
    if(arg=="red") 
    { 
    if(this_object()->query_temp("inlay/red")==8) return notify_fail("�w�g�����F.\n");
    if(!objectp(obj=present("red stone",me)) ) return 0;
    else{   
    message_vision("$N��Ū�F�_�ۦW�١G"HIR"���_\n"NOR,me); 
    message_vision(HIR"���_"HIW"�ۤƬ��@�D�����A�����b������C\n"NOR,me); 
    this_object()->add_temp("inlay/red",1);
    this_object()->delete_temp("inlay/blue"); 
    this_object()->delete_temp("inlay/white");
    this_object()->delete_temp("inlay/green");     
    destruct(obj); 
    }
    return 1;
    }
    if(arg=="blue")
    {  
    if(this_object()->query_temp("inlay/blue")==10) return notify_fail("�w�g�����F.\n");
    if(!objectp(obj=present("blue stone",me)) ) return 0;
    else{
    message_vision("$N��Ū�F�_�ۦW�١G"BLU"���_\n"NOR,me); 
    message_vision(BLU"���_"HIW"�ۤƬ��@�D�ť��A�����b������C\n"NOR,me); 
    this_object()->add_temp("inlay/blue",1);
    this_object()->delete_temp("inlay/white");
    this_object()->delete_temp("inlay/red");
    this_object()->delete_temp("inlay/green");   
    destruct(obj); 
    }
    return 1;
    } 
    if(arg=="green")
    {  
    if(this_object()->query_temp("inlay/green")==6) return notify_fail("�w�g�����F.\n");
    if(!objectp(obj=present("green stone",me)) ) return 0;
    else{
    message_vision("$N��Ū�F�_�ۦW�١G"HIG"���_\n"NOR,me); 
    message_vision(HIG"���_"HIW"�ۤƬ��@�D����A�����b������C\n"NOR,me); 
    this_object()->add_temp("inlay/green",1);
    this_object()->delete_temp("inlay/red"); 
    this_object()->delete_temp("inlay/white"); 
    this_object()->delete_temp("inlay/blue");    
    destruct(obj); 
    }
    return 1;
    }
    if(arg=="white")
    {  
    if(this_object()->query_temp("inlay/white")==4) return notify_fail("�w�g�����F.\n");
    if(!objectp(obj=present("white stone",me)) ) return 0;
    else{
    message_vision("$N��Ū�F�_�ۦW�١G"HIW"���_\n"NOR,me); 
    message_vision(HIW"���_"HIW"�ۤƬ��@�D�ե��A�����b������C\n"NOR,me);  
    this_object()->add_temp("inlay/white",1);
    this_object()->delete_temp("inlay/blue");   
    this_object()->delete_temp("inlay/red");  
    this_object()->delete_temp("inlay/green");    
    destruct(obj); 
    }
    return 1;
    }
}  
int do_godcome(string arg)
{
    object me=this_player(),ppl;
    if(arg=="blue")
    { 
     if(this_object()->query_temp("inlay/blue") !=10) return 0;
     else     message_vision("\n$N�j�ۡG�U�઺�ѯ��ڡI�Э��{�b�ڪ����e�I\n",me);  
     ppl=new(__DIR__"doll_1")->move(environment(me)); 
     this_object()->delete_temp("inlay/blue");
     return 1;
    } 
    if(arg=="red")
    { 
     if(this_object()->query_temp("inlay/red") !=8) return 0;
     else     message_vision("\n$N�j�ۡG�U�઺�ѯ��ڡI�Э��{�b�ڪ����e�I\n",me); 
     ppl=new(__DIR__"doll_2")->move(environment(me)); 
     this_object()->delete_temp("inlay/red");
     return 1;
    } 
    if(arg=="green")
    { 
     if(this_object()->query_temp("inlay/green") !=6) return 0;
     else     message_vision("\n$N�j�ۡG�U�઺�ѯ��ڡI�Э��{�b�ڪ����e�I\n",me); 
     ppl=new(__DIR__"doll_3")->move(environment(me)); 
     this_object()->delete_temp("inlay/green");
     return 1;
    }     
     if(arg=="white")
    { 
     if(this_object()->query_temp("inlay/white") !=4) return 0;
     else     message_vision("\n$N�j�ۡG�U�઺�ѯ��ڡI�Э��{�b�ڪ����e�I\n",me); 
     ppl=new(__DIR__"doll_4")->move(environment(me)); 
     this_object()->delete_temp("inlay/white");
     return 1;
    } 
}
/*
int do_inlay(string str)
{
    object obj,me; 
    me=this_player(); 
    if(this_object()->query_temp("inlay/blue") == 10) 
       return notify_fail("�̭��w�g�^�F�Q�����_�A�A�S�ݨ�ܡH\n");     
    if(this_object()->query_temp("inlay/red") == 8) 
       return notify_fail("�̭��w�g�^�F�K�����_�A�A�S�ݨ�ܡH\n");    
    if(this_object()->query_temp("inlay/green") == 6) 
       return notify_fail("�̭��w�g�^�F�������_�A�A�S�ݨ�ܡH\n");    
    if(this_object()->query_temp("inlay/white") == 4) 
       return notify_fail("�̭��w�g�^�F�|�����_�A�A�S�ݨ�ܡH\n");     
    if(!objectp(obj=present("blue stone",me)) ) 
*/


