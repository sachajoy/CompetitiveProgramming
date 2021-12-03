ll solve(ll n, ll x){
    ll box = 0;
    ll alice = n-x, bob = x;
    while(alice != bob){
        if(alice == 0 || bob == 0){
            box += alice;
            box += bob;
            break;
        }
        if(bob > alice){
            box += alice;
            bob -= alice;
        }else{
            box += bob;
            alice -= bob;
        }
    }
    return box;
}