from django.http import HttpResponse
from django.shortcuts import render
from .models import PdfPack

def home(request):
    responseHtml = '<br>'.join("hello")
    return HttpResponse(responseHtml)