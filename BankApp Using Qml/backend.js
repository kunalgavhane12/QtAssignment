.pragma library

function validateUserCredentials(uname, pword) {

    if(uname === "" || pword === "")
    {
        return 1
    }
    else
    {
        return 0
    }
}

function validateRegisterCredentials(uname, pword, pword2, hint){

    if(uname === "" || pword === "" || pword2 === "" || hint === "")
    {
        return 1
    }
    else if( pword !== pword2)
    {
        return 2
    }
    else
    {
        return 0
    }
}
