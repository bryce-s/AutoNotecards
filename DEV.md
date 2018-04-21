# this isnstalls python venv
```
conda create -n NoteCards python=3.6 anaconda # create virtual env
source activate NoteCards
pip install Django
pip install pylint_django
in vscode settings;
   "python.linting.pylintArgs": [
        "--load-plugins=pylint_django"
    ],
```

