#include <ansi.h>
inherit NPC;

void create()
{
    set_name(HIY"�ǰ�"NOR,({"evilking"}));
    set("title",HIC"�a�������D"NOR);
    set("gender","�k��");
    set("age",20);
    set("level", 300);
    set("attitude", "friendly");
    setup();

}
void init()
{
int i;
string *eid=({"hiko"});
tell_object(this_player(),HIC"�w����{�I�I\n"NOR);
for(i=0;i<sizeof(eid);i++)
{
if (this_player()->query("id")==eid[i])
{
return 0;
break;
}
}
add_action("block_cmd","", 1);
}
int block_cmd()
{
int i;
string *cmd=({"look","say"});
for(i=0;i<sizeof(cmd);i++)
{
if ((string)query_verb()==cmd[i])
{
return 0;
break;
}
}
if ( (string)query_verb() == "tell" ){
tell_object(this_player(),HIC"�Q�h�ϧL�H���I�O�աI�I\n"NOR);}
if ( (string)query_verb() == "wiz" ){
tell_object(this_player(),HIC"�O�s�F�I�I�S�ΰաI�I\n"NOR);}
if ( (string)query_verb() == "more" ){
tell_object(this_player(),HIC"moreԣ�H�A�{�b�ݤ��쪺��I�I\n"NOR);}
if ( (string)query_verb() == "edit"){
tell_object(this_player(),HIC"�Q��ԣ�H�H�O�ðʣ��I\n"NOR);}
if ( (string)query_verb() == "quit" ){
tell_object(this_player(),HIC"�Q��QUIT�j�k�H�����I�̫Ĥl�I\n"NOR);}
if ( (string)query_verb() == "call" ){
tell_object(this_player(),HIC"���Υs�F�աI�I�{�l�h���H\n"NOR);}
if ( (string)query_verb() == "update" ){
tell_object(this_player(),HIC"�{�R�a�I�I\n"NOR);}
if ( (string)query_verb() == "call" ){
tell_object(this_player(),HIC"Callԣ�H�I�Ocall�F�I�I\n"NOR);}
if ( (string)query_verb() =="summon"){
tell_object(this_player(),HIC"�A�Q�۽֣��H�O�Q��H�U���I\n"NOR);}
if ( (string)query_verb() == "ls"){
tell_object(this_player(),HIC"�A..�A���n�èӳ�I�I\n"NOR);}
if ( (string)query_verb() =="qwiz"){
tell_object(this_player(),HIC"�A�٤����߶ܡH�I\n"NOR);}
if ( (string)query_verb() =="who"){
tell_object(this_player(),HIC"���֦b�u�W�A�A���Ϊ��D�a�I�I\n"NOR);}
if ( (string)query_verb() == "goto" ){
tell_object(this_player(),HIC"�A�Q�h���H�w���I�I�I\n"NOR);}
return 1 ;
} 


