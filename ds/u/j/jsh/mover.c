#include <ansi2.h>

string logo = "�V�I�٤��ּg�ϰ�I";
int flag_logo;

void create()
{
        tell_room(find_object("/u/w/whoami/workroom"),ESC + "[2;24r" + CLR ) ;
        set_heart_beat(1);
}

void heart_beat()
{
        string show;
        int x, c;

        if( flag_logo < strlen(logo) )
        {
                flag_logo++;
//                  flag_logo = strlen(logo);
        } else flag_logo = 0;
        x = flag_logo>5?flag_logo-5:0 ;
        c = x>3?x-3:0;
                show = BLK + logo[0..c]+YEL+logo[c+1..x]+HIY+logo[x+1..flag_logo]+YEL+logo[flag_logo+1..flag_logo+3]+BLK+logo[flag_logo+4..] ;
//        show = HBRED+HIY+logo+NOR;
        tell_room(find_object("/u/a/alickyuen/workroom"), ESC+"[s"+ESC +"[1;2f"+show+ESC+"[u" );
}

// after use : eval destruct(find_object("..."));
// eval write(ESC + "[r");

