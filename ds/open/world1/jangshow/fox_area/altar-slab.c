#include <ansi.h>  
//#define RS_EN "/open/world1/tmr/area/square.c"
inherit ITEM;
void create()
{
     set_name("���¥�",({"altar slab","slab"})); 
     set("long","�@���j���Y�A�W���観�@�����W���e���A�W���g���F�ǹСA���G�ܤ[�S��L�F��F�C\n"
                "����h���� [ �p�n����(altarage)�A�Щ񲽫~�A���ũ񪰯W������A���O�I]\n");
     set("no_sac",1); 
     set("no_get",1);
     set_weight(99999999);   
     setup();
}  
void init()
{
        add_action("do_altarage","altarage");
} 

int do_altarage(string arg)
{  
    object me=this_player(),z;
        if(!me) return 0;   
        if(this_object()->query_temp("altaraged")==1) return notify_fail("���[�e�~���H�����L�C\n");
        if(!arg || arg!="�p���W������ on slab") return notify_fail("�A�n�Τ��򲽫�?\n");
        if(!objectp(z=present("corpse",me) ) )
                return notify_fail("�A�S���F��i�H������ ? \n");
        message_vision("\n$N�N�p���W�������b���¥ۤW�C\n",me);   
        this_object()->set_temp("altaraged",1); 
  {
    destruct(z); 
    message_vision("\n�p���W�������M�����¥ۤ��I�F�U�h�E�E�E�����F�I\n",me);
    call_out("GO_FOX_ONE",10);
  } 
    return 1;
}   

void GO_FOX_ONE()
{
     message("world:world1:vision",HIR"\n\n\t.........�K.........�K�K�K�K................\n\n"NOR,users()); 
     call_out("GO_FOX_TWO",5);
     return;
} 
void GO_FOX_TWO()
{
     object me=this_player(),foxp,npc,room;
     room=load_object(environment(this_object())->query("exits/southdown"));
   if( room && objectp(npc = present("miao-jian bonze",room)))
    {  
   message("world:world1:vision",HIW"\n\t�@�����j�����~�A�g�ۦ������b�ⶳ���p�A�����M�|�������E�E�E\n\n"
                    +HIC"\t���b�����E�E�E"+HIR"�t�e���ԡI\n\n"
                    +MAG"\t�j�q�����_«�ɡE�E"+HIM"�E��"+HIW"����"+NOR"�D�E�@���I\n\n"+NOR,users());
   foxp=new(__DIR__"fox");
   foxp->move(environment(this_object())); 
   npc->move(environment(this_object()));  
   npc->receive_damage("hp",12000); 
   npc->command("say �E�������I�٤��t�t�^��I�ѹ��N���Ѧ�D�E�E�j�}���١I\n",me);
   npc->kill_ob(foxp);  
   foxp->command("say �K�K�K�E�E�E���Y�E�E�A�H�������٬O�H�e���ڹ��I�ӧa�I\n",me);
   foxp->kill_ob(npc);
    } 
    call_out("stop_altaraged",1800,this_object());  
    //call_out("JUMP_DOWN_RS",5);  
   // call_out("B_SD",60);
    return; 
}  
void stop_altaraged()
{
     this_object()->delete_temp("altaraged");
     return;
}   
/************************************************
void JUMP_DOWN_RS()
{
     object foxp;  
     if(objectp(foxp = present("evil fox",this_object())));
     message("world:world1:vision",HIM"\n\t�E��"+HIW"����"+NOR"�@�D�ӤU�A���U�F�ⶳ���p�E�E\n\n"
                                   HIW"\n\t�����M�|�ĹD�G���㦹�D�@�H���j�T�ڡI�ѹ��E�E�E�E\n"
                                   HIW"\n\t              �L�ର�O�r�E�E�u�঺�u�Ǥ���}�F�I\n\n"+NOR,users());   
     foxp->move(RS_EN); 
     return;
} 
**************************************************/ 
/********************************************************************
void B_SD()
{
     object bonzep;
     if(objectp(bonzep = present("miao-jian bonze",this_object())));
     bonzep->command("go southdown");
     return;
} 
**********************************************************************/

