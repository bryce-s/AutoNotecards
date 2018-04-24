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
# migrating DB tables:
```
python3 manage.py migrate
 
```

# playing with tables in shell
```
python3 manage.py shell
from processor.models import PdfPack
>>> from processor.models import PdfPack
>>> pack = PdfPack(desc="hello", document=NULL)
Traceback (most recent call last):
  File "<console>", line 1, in <module>
NameError: name 'NULL' is not defined
>>> pack = PdfPack(desc="hello")
>>> pack.desc 
>>> hello
>>> pack.desc = "woof"
>>> pack.save() # stores in DB

```

# Testing:
```
python3 manage.py test processor
# with verbosity:
python3 manage.py test processor --verbosity=2 
```
